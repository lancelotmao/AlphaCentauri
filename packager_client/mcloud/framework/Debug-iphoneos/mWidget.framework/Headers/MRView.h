//
//  MRView.h
//  mWidget
//
//  Created by mCloud on 14/11/29.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MRuntime/MRuntime.h>
#import "PropertiesManager.h"
#import "MRLayoutParams.h"
#import "MRJSExecutor.h"

#define USE_KActionBar
#ifdef USE_KActionBar
#define ActionBar KActionBar
#else
#define ActionBar MRActionBar
#endif


#ifdef DEBUG
#define MRLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define MRLog(...)
#endif

@protocol makeLabelSizeProtocol <NSObject>
@optional
- (void)calc_label_maxSize1:(float)listViewWidth;
@end

@class MRBitmap;

@protocol MRJSView <JSExport>
/**
 *  setAttribute
 *
 *  @param attr   control attribute
 * @param value by key set attribute
 *@return id
 */
JSExportAs(setAttribute, - (void)setAttribute:(NSString*)attr fromKeyStr:(NSString*)value);
/**
 *  getAttribute
 *
 *  @param key   by key set control value(attribute)
 *@return id
 */
- (id)getAttribute:(NSString*) key;
/**
 *  setEvent
 *
 *  @param event      accepts string class event
 *  @param jsCode    string class jscode
 */
- (void)setEvent:(NSString*)event :(NSString*)jsCode;
- (void)invoke:(NSString*)method :(id)jsonArgs;
/**
 *  setX
 *
 *@param X
 */
- (void)setX:(float)x;
/**
 *  setY
 *
 *@param Y
 */
- (void)setY:(float)y;
/**
 *  getX
 *
 *@return float get controll X
 */
- (float)getX;
/**
 *  getY
 *
 *@return float get controll Y
 */
- (float)getY;
/**
 *  getWidth
 *
 *@return float get controll width
 */
- (float)getWidth;
/**
 *  getHeight
 *
 *@return float get controll height
 */
- (float)getHeight;

/**
 *  starts animation
 *
 *  @param param       accepts Javascript Object which contains all params needed
 *  @param endCallback called when animation ends
 */
- (void)startAnimation:(NSDictionary*)param :(JSValue*)endCallback;

/**
 *  stop animation
 *
 */
- (void)stopAnimation;

/**
 *  check if current view is doing animation
 *
 *  @return true if it is animation, false otherwise
 */
- (BOOL)isAnimating;
/**
 *  show fragment page by index
 *
 *
 */
- (void)showPage:(NSUInteger) index;

/**
 * Returns an immutable bitmap representing current view
 * the returned object is an MRBitmap object
 *
 */
- (MRBitmap *)snapshot;

/**
 * to adjust android ,it complete refresh and hidden the icon of refreshView
 *
 */
- (void)onRefreshComplete;

- (BOOL)requestFocus;
/**
 *  add child view
 *
 *  @param view MRView subclass object.
 */
- (void)appendChild:(MRView *)view;

@end


@protocol MRFragmentDelegate <NSObject>
- (void)onFragmentChanged:(NSUInteger) index;
@end


@class MRControlRect;

@interface MRView : MRBaseView <MRJSView, MRDataChangeDelegate,makeLabelSizeProtocol>

@property (nonatomic,readonly) UIView *view;
@property (nonatomic,copy)NSString *ID;
@property (nonatomic,readonly)NSString *bundleName;
@property (nonatomic,readonly)PropertiesManager *propertyManager;
@property (nonatomic,weak) MRJSExecutor* scriptExecutor; // Points to context's scriptExecutor
@property (nonatomic,weak) MRView *superView;
@property (nonatomic,weak) MRView *rootView;
@property (nonatomic,weak) MMLViewData *viewData; // cached data for re-creating and saving
@property (nonatomic,weak) id<MRFragmentDelegate> fragmentDelegate;
@property (nonatomic,weak) MRAnimation* anim;

@property (nonatomic,strong) NSMutableArray *items;
@property (nonatomic,strong) NSMutableDictionary *attrs;
@property (nonatomic,strong) NSMutableDictionary *events;
@property (nonatomic,strong) MRLayoutParams* layoutParams;
@property (nonatomic,strong) NSLayoutConstraint *constraintTop;
@property (nonatomic,strong) NSLayoutConstraint *constraintLeft;
@property (nonatomic,strong) NSLayoutConstraint *constraintBottom;
@property (nonatomic,strong) NSLayoutConstraint *constraintRight;
@property (nonatomic,strong) NSLayoutConstraint *constraintWidth;
@property (nonatomic,strong) NSLayoutConstraint *constraintHeight;
@property (nonatomic,strong) NSLayoutConstraint *constraintCenterX;
@property (nonatomic,strong) NSLayoutConstraint *constraintCenterY;
@property (nonatomic,assign)BOOL needFreshData;
@property (nonatomic,assign)BOOL dataHadBind;
@property (nonatomic,assign)BOOL border;
@property (nonatomic,assign)BOOL adjustPan;
@property (nonatomic,assign) BOOL hasValidLayout;
@property (nonatomic,assign)CGSize maxSize;
@property (nonatomic,readonly) id<MRDataSourceDelegate> dataSource;
@property (nonatomic,readonly)id<makeLabelSizeProtocol>makeLableSizeDelegate;
@property (nonatomic,strong) NSString *effect;
@property (nonatomic,strong) NSString *pinchGesture;
@property (nonatomic,strong) NSString *swipeGesture;
@property (nonatomic,assign) NSInteger tag;
@property (nonatomic,strong) MRControlRect* rect; // for selection
@property (nonatomic, assign) BOOL isFinishFlag;
/**
 *  indicates whether this view is performing animation or not
 */
@property (nonatomic, readwrite) BOOL animating;
- (void)onFragmentChanged:(NSInteger)index;
- (void)setAttribute:(NSString *)attr withNamespace:(NSString *)ns withValue:(NSString *)value;
- (void)setAttribute:(NSString*)attr fromKeyStr:(NSString*)value;
- (void)setAttributeWithInt:(NSInteger)attr fromKeyStr:(NSString*)value;
- (id)getAttribute:(NSString*)attr;
- (id)getAttributeWithInt:(NSInteger)attr;
- (NSDictionary*)getAllAttrs;

- (void)addView:(MRView *)view;
- (void)removeView:(MRView *)view;

- (void)onAddView:(MRView*)view;
- (void)onRemoveView:(MRView*)view;

#pragma -mark For Layout params setting
//- (void)setViewFrame:(NSString*)value;
- (void)setWidth:(NSString*)value;
- (void)setHeight:(NSString*)value;
- (void)setLeft:(NSString*)value;
- (void)setTop:(NSString*)value;
- (void)setBackGround:(NSString*)value;
- (BOOL)isVisible;
- (void)setRadius:(NSString*)value;
- (void)setDisable:(NSString*)value; //不是继承UIControl的控件需要重写setDisable方法
- (void)setVisible:(NSString*)value;
- (void)setBoardWidth:(NSString*)value;
- (void)setBoardColor:(NSString*)value;
- (void)setBorderType:(NSString*)value;
- (void)setIndex:(NSString*)value;
- (void)setbackground_normal:(NSString *)value;
- (void)setbackground_disable:(NSString *)value;


- (void)setAlignment:(NSString*)value;
- (CGRect)getFrame;
- (CGSize)measureViewSize;

- (void)setEvent:(NSString*)event :(NSString*)jsCode;
- (void)invoke:(NSString*)method :(id)jsonArgs;

- (void)bindData:(NSDictionary*) inheritedData;
- (void)updateBindedValue:(NSInteger)attr withValue:(NSString*)value;
//new
//- (void)onBinding:(NSInteger)property :(NSString *)jsName;
//- (void)callBackBindData:(NSString *)key :(NSString *)jsObject;

#pragma -mark for sub class
// sub class need to do
- (BOOL)onAttributeChanged:(NSInteger)attr :(NSString*)value;
- (id)onGetAttribute:(NSString*)attr;

// should not be overridden
- (void)finishInflate;

// called when inflation is finished
- (void)onFinishInflate;

-(BOOL)finishLayout;
-(BOOL)onFinishLayout;
-(void)finishResetLayout;

- (MRView*)findViewById:(NSString*)viewId;

/**
 *  check if a touch event hits a view or its sub view
 *  this method will recursively test the caller's sub views and return the fore-most view
 *
 *  @param point touch point in Window Space
 *
 *  @return the view or one of its sub view that passes hit test
 */
- (MRView*)hitTest:(CGPoint)point;
- (MRView*)_hitTest:(CGPoint)point :(MRView*)view;

//request Layout
- (void)resetLayoutParams;
- (void)requestLayout;
- (void)requesRootLayout;
- (void)requestLayoutForMRLable:(MRView*)aLable;

- (void) attachToNativeView:(UIView*)nativeView;

/**
 *  For Test 属性
 *
 *
 */
//- (NSArray*)testItems;
//- (NSArray*)testMethods;
//+ (NSString*)developer;
- (NSData*)dumpHierarchy;



//-(void)measure:(int)widthMeasureSpec :(int)heightMeasureSpec;
//-(float)getMeasuredHeight;
//-(float)getMeasuredWidth;


- (void)removeViewAtWindow;

- (BOOL)animation:(float)durtion;

- (void)generateBindData:(NSString*) bindInfo :(NSInteger)property;

- (CGSize)getSelfViewSize;
-(void)setBgImage:(UIImage *)bgImage;

//处理控件依赖调用统一方法
- (void)setDependenceProperty;
@end
