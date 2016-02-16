//
//  MRJQuery.h
//  MRuntime
//
//  Created by lucaiguang on 15/11/19.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JSContext;
@interface MRJQuery : NSObject
+ (void)requireWithContext:(JSContext *)context;
@property (nonatomic, strong) id selector;
@end
