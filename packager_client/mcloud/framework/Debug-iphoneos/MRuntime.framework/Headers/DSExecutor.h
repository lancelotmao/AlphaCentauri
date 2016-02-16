//
//  ActionExecutor.h
//  MRuntime
//
//  Created by lancemao on 7/21/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Executor.h"
#import "DSUnit.h"

@interface DSExecutor : NSObject 

-(void) execute:(DSUnit*)action;


@end
