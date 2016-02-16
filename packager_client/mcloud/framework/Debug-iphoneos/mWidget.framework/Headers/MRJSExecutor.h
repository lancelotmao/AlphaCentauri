//
//  MRJSExecutor.h
//  MRCore
//
//  Created by lucaiguang on 14/12/1.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MMLData.h"

@class MMLFileSource;
@class MMLInflater;

@class MRView,MRActionBar, MRViewController;

@interface MRJSExecutor : MRBaseScriptExecutor <MRScriptExecutor, MRJSExport>

@property (nonatomic, strong) id context;
@property (nonatomic, strong) NSMutableDictionary *dataSources;
@property (nonatomic, strong) dispatch_queue_t jsQueue;
@property (nonatomic, strong) NSString *baseDir;
@property (nonatomic, strong) MMLFileSource *fileSource;
@property (nonatomic, strong) MMLInflater *inflater;
@property (nonatomic, weak) MRViewController *jsVc;

@property (nonatomic, assign) BOOL isInterpret;
@property (nonatomic, strong) NSString *projectId;
//@property (nonatomic) MRView* rootView;
//@property (nonatomic) MRActionBar* actionBar;
//@property (nonatomic, assign) MRViewController* pageDelegate;

// contains only JS code
- (instancetype)initWithJS:(NSString *)js;

// has XML CDATA
- (instancetype)initWithActionData:(MMLActionData*)data :(NSString*)fileName;

/**
 *  upload all JS code to JSContext at once
 */
- (void)uploadJS;

/**
 *  @param jscode eg. @"callNativeFunctionSync('天兔','test', null, 0)"
 */
- (id)execute:(NSString*)scriptCode :(NSString*)handlerID;

/**
 *  js code添加额外的属性
 *
 *  @param name     属性名 （属性名不能为callNativeFunctionSync）
 *  @param instance 实例
 *
 *  @return 是否添加成功
 */
- (BOOL)addContextAttribute:(NSString *)name withInstance:(id)instance;

- (id)scriptObject:(NSString *)objectName;

- (void) stop;

@end
