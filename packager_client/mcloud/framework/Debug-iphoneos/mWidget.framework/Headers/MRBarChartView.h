//
//  MRBarChartView.h
//  Chart
//
//  Created by ywx272253 on 15/3/11.
//  Copyright (c) 2015年 com.huawei.hwcloud. All rights reserved.
//

#import "ChartView.h"

#define chartMargin     10

typedef enum : NSUInteger {
    BarOrientationVertical,
    BarOrientationHorizontal,
    
} BarOrientation;

@interface MRBarChartView : ChartView

@property (nonatomic) BarOrientation barOrientation;

@property (nonatomic) CGFloat xLabelWidth;

@property (nonatomic, assign) BOOL showRange;

@property (nonatomic, assign) CGRange chooseRange;

@property (nonatomic, readonly) ChartMarkView *contentView;

@end
