//
//  MRScrollPalyView.h
//  MRuntime
//
//  Created by hushengcai on 15/11/24.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import "MRView.h"


@interface MRScrollPlayView : MRView

@property (nonatomic,strong)UIView *scrollPlayView;

- (void)stopTimer;
- (void)startTimer;

@end
