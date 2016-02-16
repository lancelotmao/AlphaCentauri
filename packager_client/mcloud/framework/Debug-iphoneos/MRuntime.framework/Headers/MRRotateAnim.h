//
//  MRRotateAnim.h
//  MRuntime
//
//  Created by Lancelot on 4/7/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import "MRAnimation.h"

@interface MRRotateAnim : MRAnimation

@property (readwrite) double x;
@property (readwrite) double y;
@property (readwrite) double z;

- (id)initWithUid:(NSString *)uId from:(double)from to:(double)to duration:(double)duration repeat:(BOOL)repeat X:(double)x Y:(double)y Z:(double)z;

@end
