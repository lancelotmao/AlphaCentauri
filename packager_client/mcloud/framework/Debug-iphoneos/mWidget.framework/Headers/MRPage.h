//
//  MRPage.h
//  mWidget
//
//  Created by Lancelot on 2/27/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

//#import "MRActionBar.h"
#import "KActionBar.h"
#import "MRView.h"

@interface MRPage : NSObject

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic, strong) NSString* title;

/*!
 @property
 @abstract
 @discussion without suffix
 */
@property (nonatomic, strong) NSString* filePath;

/*!
 @property
 @abstract
 @discussion
 */
//@property (nonatomic, strong) MRActionBar* actionBar;
@property (nonatomic, strong) ActionBar* actionBar;

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic, strong) MRView* rootView;

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic, strong) NSMutableArray* listViews;

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic, readwrite) BOOL isFragment;

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic, assign) BOOL showActionBar;

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic, strong) NSString *orientation;

/*!
 @property
 @abstract
 @discussion
 */
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;

@property (nonatomic, copy) NSString *statusColor;
/*!
 @property
 @abstract raw data of mml
 @discussion
 */
@property (nonatomic, strong) MMLData* mml;

- (void)findAllListView;
- (void)writeToFile;

@end
