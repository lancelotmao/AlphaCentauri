//
//  MRRingChartView.h
//  MRuntime
//
//  Created by ywx272253 on 15/6/29.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import "ChartView.h"
#import "RingChartView.h"

@interface MRRingChartView : ChartView

@property (nonatomic, readonly) RingChartView *innerChartView;

@end
