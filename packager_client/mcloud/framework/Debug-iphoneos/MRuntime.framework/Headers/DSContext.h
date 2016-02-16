//
//  ActionContext.h
//  MRuntime
//
//  Created by lancemao on 7/21/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import "Executor.h"

@interface DSContext : MRJSBridge <MRScriptExecutor>

@property (strong) NSMutableDictionary* data;
@property (nonatomic, strong) NSDictionary* actions;

- (instancetype)initWithFile:(NSString*)filePath;
- (instancetype)initWithData:(NSData*)data;



- (id)execute:(NSString*)scriptCode :(NSString*)handlerId;
- (void)callHandler:(NSString*)handlerId withParams:(NSDictionary*)params;
- (id<MRDataSourceDelegate>)getDataSource:(NSString *)source fromObserver:(id<MRDataChangeDelegate>) observer;
- (id)scriptObject:(NSString *)objectName;
- (void)stop;


@end
