//
//  Executor.h
//  MRuntime
//
//  Created by chengxinqing on 15/6/30.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#ifndef MRuntime_Executor_h
#define MRuntime_Executor_h
#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "MRBaseDataSource.h"
#import "MRScript.h"
#import "MRJSBridge.h"

@class MRView;
@class MRImageView;
@protocol MRScriptExecutor <NSObject>

@optional
/**
 *  execute
 *
 *  @param scriptCode  listView bind data
 *  @param handlerId   page name
 * control event a import method
 */
- (id)execute:(NSString*)scriptCode :(NSString*)handlerId;
/**
 *  callHandler
 *
 *  @param handlerId  event name for example [self.events objectForKey:@"onClick"]
 *  @param params   new value and old value
 * control event a import method
 */
- (void)callHandler:(NSString*)handlerId withParams:(NSDictionary*)params;

/**
 *  getDataSource
 *
 *  @param source  listView bind data source for example users
 *  @param observer   bing object for example label
 * listView bind data a import method
 */
- (id<MRDataSourceDelegate>)getDataSource:(NSString *)source fromObserver:(id<MRDataChangeDelegate>) observer;
/**
 *  scriptObject
 *
 *  @param objectName  event name
 *
 *@return id
 */
- (id)scriptObject:(NSString *)objectName;

/**
 *  stop
 *
 *
 *stop controller called
 */
- (void)stop;
///**
// *  getBindInfo
// *
// *  @param source   ${}
// *  @param targetView   control name
// *  @param property   bind attribute
// *
// */
//- (MRView *)getBindInfo:(NSString *)source :(MRView *)targetView :(NSString *)property;
///**
// *  getJSObject
// *
// *  @param jsObject
// * bind data menthod
// *
// */
//- (id)getJSObject:(NSString *)jsObject;
///**
// *  setJSObject
// *
// *  @param setJSObject
// *  @param value
// *  @param jsObject
// * bind data menthod
// *
// */
//- (void)setJSObject:(NSString *)key :(NSString *)value :(NSString *)jsObject;
////- (void)startPage:(NSString*)pageId :(NSDictionary*)data;
@end



@class MRView;
@class MRActionBar;
@class MRViewController;
@class KActionBar;


@interface MRBaseScriptExecutor : MRJSBridge <MRScriptExecutor, MRJSExport>

@property (nonatomic) MRView* rootView;
#ifdef USE_KActionBar
@property (nonatomic) KActionBar* actionBar;
#else
@property (nonatomic) KActionBar* actionBar;//兼容KActionBar
#endif

@property (nonatomic, assign) BOOL pageJumpInvalidate;

@end

#endif
