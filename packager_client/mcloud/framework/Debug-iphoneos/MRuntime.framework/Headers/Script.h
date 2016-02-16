//
//  Script.h
//  MRuntime
//
//  Created by mCloud on 15/7/24.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <JavaScriptCore/JavaScriptCore.h>

typedef JSValue ScriptValue;

@protocol IScript <NSObject>

-(ScriptValue*)execute:(NSString*)code;
-(ScriptValue*)scriotObject:(NSString*)objName;

@end


@interface JavaScript : NSObject <IScript>

@end


@interface Python : NSObject <IScript>

@end