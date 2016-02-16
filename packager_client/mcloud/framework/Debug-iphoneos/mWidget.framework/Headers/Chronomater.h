//
//  Chronomater.h
//  MRuntime
//
//  Created by songRao on 15/4/10.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface Chronomater : UIView
@property (nonatomic, strong) NSString *timeFormat;
@property (nonatomic, strong) NSString *countStyle;
@property (nonatomic, assign) CGFloat startTime;
@property (nonatomic, assign) CGFloat endTime;
@property (nonatomic, assign) CGFloat timeInterval;
@end
