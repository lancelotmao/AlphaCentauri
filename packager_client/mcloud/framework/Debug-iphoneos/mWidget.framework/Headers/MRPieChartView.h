//
//  MRPieChartView.h
//  Chart
//
//  Created by ywx272253 on 15/3/10.
//  Copyright (c) 2015年 com.huawei.hwcloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ChartView.h"
#import "PieChartView.h"

@interface MRPieChartView : ChartView

@property (nonatomic, readonly) PieChartView *innerChartView;

@end
