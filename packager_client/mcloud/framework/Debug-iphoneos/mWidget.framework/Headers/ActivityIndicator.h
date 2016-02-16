//
//  ActivityIndicator.h
//  MRAPI
//
//  Created by zhouguoqiang on 15/1/19.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol MRActivityExport <JSExport>
- (void)dismiss;
@end

@interface ActivityIndicator : UIView<MRActivityExport>
- (id)initWithFrame:(CGRect)frame;
- (void)start;
- (void)stop;
@property (nonatomic, assign, readonly) BOOL Start;
@property (nonatomic, strong) NSObject *observer;
+ (ActivityIndicator *)createIndicatorView;
- (void)dismiss;
@end
