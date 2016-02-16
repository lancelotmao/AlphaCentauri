//
//  MRTouchEvent.h
//  MRuntime
//
//  Created by Lancelot on 4/24/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MRTouchEvent : NSObject

@property (nonatomic, readwrite) int type;
@property (nonatomic, readwrite) float x;
@property (nonatomic, readwrite) float y;

@end
