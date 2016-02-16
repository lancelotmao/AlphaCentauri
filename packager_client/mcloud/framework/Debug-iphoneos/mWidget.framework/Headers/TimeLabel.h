//
//  TimeLabel.h
//  Chronomete
//
//  Created by songRao on 15/4/2.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CountTimeDelegate <NSObject>

- (void)timeover;

@end

@interface TimeLabel : UILabel{
    NSDate *startCountDate;
    NSDate *pauseCountDate;
    NSDate *currentTime;
    NSTimer *_timer;
}

@property (nonatomic,strong) NSString *timeFormat;
@property (assign,readonly) BOOL counting;
@property (nonatomic,strong) NSString *countStyle;
@property (nonatomic,assign) CGFloat startTime;
@property (nonatomic, assign) CGFloat endTime;
@property (nonatomic, assign) CGFloat timeInterval;
@property (nonatomic, weak) id<CountTimeDelegate>countDelegate;

- (void)start;
- (void)pause;
- (void)reset;

@end
