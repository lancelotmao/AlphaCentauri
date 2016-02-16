//
//  MRAnimation.h
//  MRuntime
//
//  Created by Lancelot on 4/7/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface MRAnimation : NSObject

@property (strong)    NSString       *uid;
@property (readwrite) double          from;
@property (readwrite) double          to;
@property (readwrite) double          duration;
@property (readwrite) BOOL            repeat;
@property (readwrite) UIImageView    *resource;

- (id)initWithUid:(NSString *)uId from:(double)from to:(double)to duration:(double)duration repeat:(BOOL)repeat;

- (void)startAnimation4view:(UIView*)view;

- (void)stop;

@end
