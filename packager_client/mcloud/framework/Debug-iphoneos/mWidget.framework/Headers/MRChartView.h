//
//  MRChartView.h
//  Chart
//
//  Created by ywx272253 on 15/3/20.
//  Copyright (c) 2015年 com.huawei.hwcloud. All rights reserved.
//

#import "MRView.h"

@interface MRChartView : MRView<MRJSView>


@property (nonatomic, strong) NSString *chartType;
@property (nonatomic, strong) NSString *chartTitle;
@property (nonatomic, strong) NSString *titleColor;
@property (nonatomic, strong) NSString *titleFontSize;
@property (nonatomic, strong) NSArray *xLabels;
@property (nonatomic, strong) NSArray *data;
@property (nonatomic, strong) NSArray *colors;
@property (nonatomic, strong) NSArray *groupTitles;
@property (nonatomic, strong) NSString *urlString;
@property (nonatomic) BOOL legendVisible;


@end
