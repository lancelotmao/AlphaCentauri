//
//  MRScript.h
//  MRuntime
//
//  Created by Lance Mao on 1/9/15.
//  Copyright (c) 2015 HuaWei. All rights reserved.
//

#ifndef MRuntime_MRScript_h
#define MRuntime_MRScript_h

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "MRBaseDataSource.h"

@class MRView, MRBitmap, MRCanvas;
@protocol MRJSExport <JSExport>

#pragma mark - coreJSApi
/**********************************************************************************************************************/
/**
 *  startBundleWithBundleName
 *
 *  @param bundleName   by bundleName startBundle
 *
 */
- (void)startBundleWithBundleName:(NSString *)bundleName;

/**
 *  startViewController
 *
 *  @param viewController   a viewcontroller object
 *
 */
- (void)startViewController:(UIViewController *)viewController ;

/**
 *  stopViewController
 *
 *  @param viewController   a viewcontroller object
 *
 */
- (void)stopViewController:(UIViewController *)viewController;

/**
 *  callNativeFunctionAsync
 *
 *  @param arguments   jsValue callback
 *
 */
- (void)callNativeFunctionAsync:(JSValue *)arguments;

/**
 *  getElementById
 *
 *  @param viewId   by viewId find view control
 *@return MRView
 */
- (MRView*) getElementById:(NSString*) viewId;

/**
 *  notifyDataSourceChanged
 *
 *  @param source   dataSource change call method user listView
 *
 */
- (void)notifyDataSourceChanged:(NSString *)source;

/**
 *  startPage
 *
 *  @param pageId   string class param start pageName by id find
 *  @param data     dictionary param startPage send data to next page
 *
 */
- (void)startPage:(NSString*)pageId :(NSDictionary*)data;

/**
 *  finishPage
 *
 *  @param data     dictionary param stop this page send data
 *
 */
- (void)finishPage:(NSDictionary *)data;

/**
 *  getPageParam
 * 
 * get after page param
 *  @return NSDictionary
 *
 */
- (NSDictionary *)getPageParam;

/**
 *  getPageParamProperty
 *
 *  @param key     by key find param property
 *@return JSValue
 */
- (JSValue *)getPageParamProperty:(NSString *)key;

- (NSString *)platforms;




#pragma mark - configJSApi
/**********************************************************************************************************************/


/**
 *  setLocalConfig
 *
 *  @param key     by key write data to local
 * @param value    write data
 * @return id
 *
 */
-(void)setLocalConfig:(NSString *)key :(NSString *)value;

/**
 *  getLocalConfig
 *
 *  @param key     by key get local data
 * @param defaultValue    if local data is nil
 * @return id
 *
 */
-(id)getLocalConfig:(NSString *)key :(NSString *)defaultValue;

/**
 *  getRuntimeVersion
 * get runtime version
 * @return double
 *
 */
-(double)getRuntimeVersion;

//动态为MML添加元素
- (id)createView:(NSString *)bundleName :(NSString *) methodName :(NSDictionary *)dict;
- (id)createMRView:(NSString *)viewName;


#pragma mark - widgetJSApi
/**********************************************************************************************************************/

//showPopMenu
/**
 *  showPopupMenu
 *@param atViewId by viewId find pop local
 *@param items pop data source
 *@param background color
 *@param callbackFun pop call event
 *
 *
 */
- (void)showPopupMenu:(NSString *)atViewId :(NSArray *)items :(NSString *)color :(JSValue *)callbackFun;

- (void)showPopupWindow:(NSString *)atView :(NSString *)contentView :(NSString *)positionX :(NSString *)positionY :(NSString *)width :(NSString *)height;
//5-15
/**
 *  showProgressDialog
 *param title 
 *param message
 *param format
 *param array
 *param callbackFun
 * @return id
 *
 */



/**
 *  show
 *  show activity
 *  @param identifier     by identifier find this object
 *@return id
 */
- (id)show:(NSString *)identifier;

/**
 *  dismiss
 *  dismiss activity
 *  @param identifier     by identifier find this object
 *@return id
 */
- (void)dismiss:(NSString *)identifier;

/**
 *  showAnimatedDatePicker
 *
 *  @param animationType     animationType have datepicker and alert
 *
 */
//- (void)showAnimatedDatePicker:(NSString *)animationType;

/**
 *  showAnimatedDatePicker
 *
 *  @param animationType     animationType have datepicker and alert
 *  @param title     datePicker title
 *  @param nowTime     nowTime for example 16:20
 *  @param format     data format for example yyyyy-MM-dd
 *  @param cancelButton     cancel button callback
 *  @param otherButton     sure button callback
 *
 */
- (void)showAnimatedDatePicker:(NSString *)animationType : (NSString *)title : (NSString *)nowTime : (NSString *)format : (JSValue *) cancelButton : (JSValue *) otherButton;

/**
 *  showAnimatedConfirmDialog
 *
 *  @param title     alert title
 *  @param message     alert message
 *  @param animationType     animationType have datepicker and alert
 *
 */
- (void)showAnimatedConfirmDialog:(NSString *)title :(NSString *)message :(NSString *)animationType;

/**
 *  showTimePickerDialog
 *
 *  @param ID     string class
 *  @param title     timepicker title
 *  @param nowTime     nowTime
 *  @param format     time format
 *  @param cancelButton     cancel button callback
 *  @param otherButton     other button callback
 *
 */
JSExportAs(showTimePickerDialog,- (id)showTimePickerDialog :(NSString *)ID : (NSString *)title : (NSString *)nowTime : (NSString *)format : (JSValue *) cancelButton : (JSValue *) otherButton);

/**
 *  showNumberPickerDialog
 *
 *  @param ID     string class
 *  @param title     numberPicker title
 *  @param defaultNum    numberPicker defalut value
 *  @param minNum     min num
 *  @param maxNum     max num
 *  @param cancelButton     cancel button callback
 *  @param otherButton     other button callback
 *
 */
JSExportAs(showNumberPickerDialog,- (id)showNumberPickerDialog : (NSString *)ID : (NSString *)title :(NSString *)defaultNum : (NSString *)minNum :(NSString *)maxNum :(JSValue *) cancelButton : (JSValue *) okButton);

/**
 *  showDatePickerDialog
 *
 *  @param ID     string class
 *  @param title     datePicker title
 *  @param nowDate    datePicker now date
 *  @param minDate     min date
 *  @param maxDate     max date
 *  @param format     date picker date type
 *  @param cancelButton     cancel button callback
 *  @param otherButton     other button callback
 *
 */

JSExportAs(showPickerViewDialog,- (id)showPickerViewDialog : (NSString *)type : (NSString *)title :(NSString *)defaultValue : (NSString *)minValue :(NSString *)maxValue :(JSValue *) cancelButton : (JSValue *) okButton);
/**
 *  showDatePickerDialog
 *
 *  @param type     pickerView type
 *  @param title     pickerView title
 *  @param defaultValue
 *  @param minValue
 *  @param maxValue
 *  @param cancelButton     cancel button callback
 *  @param otherButton     other button callback
 *
 */

JSExportAs(showDatePickerDialog,- (id)showDatePickerDialog : (NSString *)ID :(NSString *)title andOKButton : (JSValue *)okButton andCancelButton : (JSValue *)cancelButton andNowdate : (NSString *)nowDate andMaxdate : (NSString *)maxDate andMindate : (NSString *)minDate :(NSString *)format);

/**
 *  showToast
 *
 *  @param message     toast message
 *  @param dalayTime     dalay time after dismiss
 * @return id
 *
 */
- (id)showToast:(NSString *)message :(NSString *)dalayTime;


/**
 *  showMessageConfirmDialog
 *  @param width      alert width
 *  @param height     alert height
 *  @param title      alert title
 *  @param message     alert height
 *  @param radius      alert radius
 *  @param textColor     text textColor
 *  @param textSize      text textSize
 *  @param cancelButtonFunction  called when touch up inside cancel button
 *  @param okButtonFunction  called when touch up inside okButton button
 * @return id
 *
 */
- (id)showMessageConfirmDialog:(CGFloat)width :(CGFloat)height :(NSString *)title :(NSString *)message :(int)radius :(NSString *)textColor :(NSString *)textSize :(JSValue *) cancelButtonFunction : (JSValue *) okButtonFunction;

/**
 *  showMessageConfirmDialog
 *  @param title      alert title
 *  @param message     alert message
 *  @param cancelButtonFunction  called when touch up inside cancel button
 *  @param okButtonFunction  called when touch up inside okButton button
 * @return id
 *
 */
- (id)showMessageConfirmDialog:(NSString *)title :(NSString *)message :(JSValue *)okButtonFunction :(JSValue *)cancelButtonFunction;

- (id)showDialog:(NSString *)title  :(JSValue *)callbackFun;

//show local notification
/**
 *  showNotification
 *  @param fireData      notification type
 *  @param alertAction    action message
 *  @param content  notification content
 *  @param icon  called when touch up inside okButton button
 *  @param tiker   title  sound  vibrate ligths  flags  intent
 *  @param title
 *  @param  sound
 *  @param  vibrate
 *  @param  ligths
 *  @param  flags
 *  @param  intent
 * @return id
 *
 */
- (id)showNotification:(NSString *)fireData :(NSString *)alertAction :(NSString *)content :(NSString *)icon :(NSString *)tiker :(NSString *)title :(NSString *)sound :(NSString *)vibrate :(NSString *)ligths :(NSString *)flags :(NSString *)intent;

- (id)showAnimationImage:(NSArray *)imageArray;

//- (void)runLoopImage:(NSArray *)imageArr :(MRImageView *)imageView;

- (void)dismissRunLoopImage;

#pragma mark - LogJSAPI
/**********************************************************************************************************************/

/**
 * log
 *  @param logmsg log message
 *
 * print some log
 */

- (void)log:(JSValue *)logmsg;
/**
 *  日志相关JS API: JS中直接调用日志函数输出相应日志信息
 */

/**
 *  设置是否开启控制台日志打印
 *
 *  @param isConsole 是否开启
 */
- (void)setEnableConsoleLog:(BOOL)isConsole;
/**
 *  设置是否开启日志存储到文件
 *
 *  @param isFile 是否开启
 */
- (void)setEnableFileLog:(BOOL)isFile;
/**
 *  设置日志打印级别
 *
 *  @param level 0 - all    ,1- NONE, ERROR
 */
- (void)setPrintLevel:(NSString *)level;
/**
 *  打印ERROR级别日志
 *
 *  @param message 日志内容
 */
- (void)printError:(NSString *)message;
/**
 *  打印Warning级别日志
 *
 *  @param message 日志内容
 */
- (void)printWarning:(NSString *)message;
/**
 *  打印Process级别日志
 *
 *  @param message 日志内容
 */
- (void)printProcess:(NSString *)message;
/**
 *  打印Info级别日志
 *
 *  @param message 日志内容
 */
- (void)printInfo:(NSString *)message;
/**
 *  打印Debug级别日志
 *
 *  @param message 日志内容
 */
- (void)printDebug:(NSString *)message;
/**
 *  打印Verbose级别日志
 *
 *  @param message 日志内容
 */
- (void)printVerbose:(NSString *)message;
JSExportAs(printError,   - (void)printError:(NSString *)traceID withMsg:(NSString *)message);
JSExportAs(printWarning, - (void)printWarning:(NSString *)traceID withMsg:(NSString *)message);
JSExportAs(printProcess, - (void)printProcess:(NSString *)traceID withMsg:(NSString *)message);
JSExportAs(printInfo,    - (void)printInfo:(NSString *)traceID withMsg:(NSString *)message);
JSExportAs(printDebug,   - (void)printDebug:(NSString *)traceID withMsg:(NSString *)message);
JSExportAs(printVerbose,   - (void)printVerbose:(NSString *)traceID withMsg:(NSString *)message);

#pragma mark - AppJSApi
/**********************************************************************************************************************/

- (id)appStoreVersion:(NSString*)params;
- (void)runInMainThread:(JSValue*)blockStr :(NSString*)params;
- (BOOL)isLatestApp:(NSString *)appId version:(NSString *)version;
- (BOOL)isCanOpenApplication:(NSString *)localUrl;
- (BOOL)openOtherApplication:(NSString *)localUrl;
- (BOOL)installApplication:(NSString *)bundleAlias;
- (int)appStatus:(NSString *)version :(NSString *)bundleIdentifier :(NSString *)localUrl;
- (void)installApp:(NSString *)bundleIdentifier;
- (void)runInBackground:(JSValue*)blockStr :(NSString*)params;
- (NSString *)getFilesDir;

#pragma mark - bunudleJSApi
/**********************************************************************************************************************/

/**
 *  callForJS
 *  打电话api
 *  @param phoneNum     call phone num
 * @return id
 *
 */
-(id)call:(NSString *)phoneNum;

/**
 *  sendMessage
 *   发短信api
 *  @param phoneNum     phone num
 * @param body     message content
 * @return id
 *
 */
-(id)sendSms:(NSArray *)phoneNum :(NSString *)body;

- (void)saveDocument:(NSString *)userName :(NSString *)filePath :(NSString *)saveFileName;

- (void)openDocument:(NSString *)userName :(NSString *)savedFileName;

/**
 *  @params
 *
 *  通讯录操作
 */
- (NSString *)chineseToPinYin:(NSString *)sourceString;

/**
 *  获取手机通讯录列表
 */
- (NSMutableArray *)getAddressBookFromPhone;

//- (void)fillData;



/**
 * setTimeout
 *  @param callback call back after timeout
 *  @param timeout  time
 *
 * often use auto login
 */
- (void)setTimeout:(JSValue*) callback :(int) timeout;


/*
 * security lock
 */
- (void)securityLock:(JSValue *)pwdErrorCallBack;



- (id)inflateMML:(NSString*)fileName :(MRView*)layout;

- (id)getBundleList;

#pragma mark - devieceJSApi
/**********************************************************************************************************************/

/**
 * getDeviceId
 *
 * get device id
 * return NSString
 */
- (NSString*)getDeviceId;
- (void)setGlobalData:(id)key :(id)object;
- (id)getGlobalData:(id)key;
- (float)getScreenWidth;
- (float)getScreenHeight;
- (NSString *)getUUID:(JSValue *)value;

#pragma mark - toolsJSApi

- (void)setBaseDir:(NSString *)pathString;
//
//- (NSString *)setBaseDir;
//
//- (NSString *)getBaseDir;

- (void)setMMLUnZipDir:(NSString *)pathString;
- (NSString *)getMMLUnZipDir;

#pragma mark - bitmap
- (MRBitmap *)createBitmap:(NSNumber *)width :(NSNumber *)height :(NSDictionary *)config;
- (MRCanvas *)createCanvas:(MRBitmap *)bitmap;

#pragma mark - basic

- (void)setIsInterpretMode:(BOOL)isInterpret;
- (BOOL)getIsInterpretMode;
- (void)setProjectId:(NSString *)projectId;
- (NSString *)getProjectId;

- (id)createElement:(NSString *)element;
@end


#endif
