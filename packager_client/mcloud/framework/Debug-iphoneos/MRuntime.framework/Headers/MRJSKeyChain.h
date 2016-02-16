//
//  MRJSKeyChain.h
//  MRuntime
//
//  Created by lucaiguang on 15/11/28.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JSContext;
@interface MRJSKeyChain : NSObject
+ (void)requireWithContext:(JSContext *)context;

- (void)save:(NSString *)key :(id)object;
- (id)get:(NSString *)key;
@end
