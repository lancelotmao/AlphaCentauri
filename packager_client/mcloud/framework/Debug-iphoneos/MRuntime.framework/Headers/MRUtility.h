//
//  MRUtility.h
//  MRuntime
//
//  Created by lancemao on 9/19/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MRUtility : NSObject

+ (BOOL)isJailbreak;
+ (NSString *)stringFromDate:(NSDate *)date withFormat:(NSString *)format;

@end
