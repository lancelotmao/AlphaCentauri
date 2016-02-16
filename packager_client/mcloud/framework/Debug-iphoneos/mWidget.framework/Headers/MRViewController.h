//
//  MRViewController.h
//  mWidget
//
//  Created by Lancelot on 3/17/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MRPage.h"
#import "MRJSExecutor.h"
#import "MRControlRectManager.h"

@class MRFragmentSwitcher;

@protocol MRViewControllerDelegate <NSObject>

- (void)editMML:(NSString *)fileName :(MRViewController *)viewcontroller :(UIImage *)image;

@end


@class MRLayout;
@class MRFragment;

/*!
 @interface 
 @abstract Base View Controller for mCloud application
 @discussion MRViewController provides extended functionality of a UIViewController.
 It contains page, which in turn has action bar and views
 */
@interface MRViewController : UIViewController <UIActionSheetDelegate>

/*!
 @property
 @abstract bundle context stores dynamically loaded bundle information
 @discussion
 */
@property (nonatomic, weak) MRContext* bundleContext;

/*!
 @property
 @abstract
 @discussion stores page data like action bar, views. in case of fragment switcher, we only store
 the top-most page
 */
@property (nonatomic,strong) MRPage *page;

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic,strong) MRLayout *rootLayout;

/*!
 @property
 @abstract page context stores page information
 @discussion
 */
@property (nonatomic, strong) MRContext* context;

/*!
 @property
 @abstract contains all contexts of all fragments
 @discussion
 */
@property (nonatomic, strong) NSMutableArray* contexts;

/*!
 @property
 @abstract current pg and act file name
 @discussion
 */
@property (nonatomic, copy) NSString* fileName;

// stores pg and act as string
@property (nonatomic, copy) NSString* strMML;
@property (nonatomic, copy) NSString* strAct;


//left and right button for MREditViewController
@property (nonatomic, strong) UIButton *leftButton;
@property (nonatomic, strong) UIButton *rightButton;

/*!
 @property
 @abstract raw data of mml
 @discussion
 */
@property (nonatomic, strong) MMLData* mml;

/*!
 @property
 @abstract Javascript executor
 @discussion
 */
@property (nonatomic, strong) MRBaseScriptExecutor* jsApi;

/*!
 @property
 @abstract parameters passed between pages
 @discussion when start another page, we can pass some data to the target page using this property
 and similarly, when finish a page, data can be passed to the previous page
 */
@property (nonatomic, strong) NSDictionary* pageParam;

/*!
 @property
 @abstract first view controller. if current view controller's navigation controller becomes nil
 we can try get navigation controller from the first view controller
 @discussion
 */
@property (weak) UIViewController* root;

/*!
 @property
 @abstract whether this view controller is the first page
 @discussion
 */
@property (nonatomic, readwrite) BOOL isStartPage;

/*!
 @property
 @abstract file source can be used for file manipulations
 @discussion
 */
@property (nonatomic, strong) MMLFileSource *fileSource;

/*!
 @property
 @abstract corresponding to 'showActionBar' attribute in mml
 @discussion
 */
@property (nonatomic) BOOL navigationBarHidden;
@property (nonatomic,strong) NSString *orientation;
@property (nonatomic,strong) MRLayout *parserLayout;

/**
 *  Highlight rect
 */
@property (nonatomic,strong) MRControlRectManager* rectMan;

@property (nonatomic,strong) NSString *projectName;
@property (nonatomic,strong) NSString *vcFileName;
@property (nonatomic,strong) NSString *pgName;
@property (nonatomic,assign) id<MRViewControllerDelegate>MRDelegate;

/*!
 @property
 @abstract for Javascript debug
 @discussion when in debug mode, we will upload Javascript code to Safari before we call page life-cycle
 methods like onCreate, so that we can harness Safari's debug feature
 */
@property (nonatomic) BOOL debugMode;

/*!
 @property
 @abstract whether or not this view controller has been marked as 'popped'
 @discussion this is for Android compatibility. Imagine user first call startPage, then call finishPage
 in iOS, the newly pushed view controller will be popped immediately, because both view controller share
 the same navigation view controller. So, instead of popping right away,
 we will just mark the previous view controller as 'popped', 
 now if user really pop the current view controller, we will actually pop two, since we know the last one is
 marked as 'popped' 
 */
@property (nonatomic, readwrite) BOOL popped;

- (void)onStartPage:(NSString *)pageId :(NSDictionary*)data;
- (void)onFinishPage:(NSDictionary*)data;
- (id)onPushViewController :(NSString*)pageId :(NSDictionary*)data;
- (void)onPopViewController :(NSDictionary*)data;
- (NSDictionary*)onGetPageParam;

- (MRView*)findViewById:(NSString*)viewId;
- (void)refresh :(NSString*)fileName :(NSString*)data;
- (NSData *)preview :(NSString*)fileName :(NSString*)pg :(NSString*)act;
- (void)selectionChanged:(NSString *)viewID;
- (void)dispatchTouchEvent:(MRTouchEvent*)event;
- (void)finish;
- (void)addDebugMenu;

- (void)onFragmentChanged:(MRFragment *)fragment;

- (void)addFragmentSwitcher:(MRFragmentSwitcher *)fragmentSwticher;

//处理statusBar的颜色
- (void)setStatusBarBackground:(NSString *)color;
@end
