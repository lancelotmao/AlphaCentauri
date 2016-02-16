//
//  MRJSObjectDataSource.h
//  MRAPI
//
//  Created by mCloud on 15/1/9.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <MRuntime/MRuntime.h>

@class MRJSBridge;
@interface MRJSObjectDataSource : MRBaseDataSource

- (instancetype)initWithJSObjectName:(NSString *)name andContext:(MRJSBridge *)context;

@end
