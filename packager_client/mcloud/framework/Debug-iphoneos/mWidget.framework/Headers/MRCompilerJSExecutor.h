//
//  MRCompilerJSExecutor.h
//  MRAPI
//
//  Created by rossyang on 15/3/23.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import "MRJSExecutor.h"

@interface MRCompilerJSExecutor : MRJSExecutor

- (void)callHandler:(NSString*)handlerId withParams:(NSDictionary*)params;

@end
