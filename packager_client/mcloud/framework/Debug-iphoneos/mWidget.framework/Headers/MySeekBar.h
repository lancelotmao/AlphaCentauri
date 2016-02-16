//
//  MySeekBar.h
//  mWidget
//
//  Created by kefoqing on 14/12/19.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <MRuntime/MRuntime.h>

@protocol seekBarValueChangeDelegate <NSObject>

- (void)valueChange:(CGFloat)value andOldValue:(CGFloat)oldValue;
@end
@interface MySeekBar : UIView

@property (nonatomic, assign) id <seekBarValueChangeDelegate>delegate;
@property (nonatomic,strong) NSString *backgroundStr;//背景图片字符串

@property (nonatomic,strong) UIImageView *bgImageView;
@property (nonatomic,strong) UIImage *progressBarImage;//进度条图片
@property (nonatomic,strong) UIImage *barImage;//划块的图片

@property (nonatomic,assign) float barValue;//进度条的值
@property (nonatomic,assign) float maxvBarValue;//最大值
@property (nonatomic,assign) float minvBarValue;//最小值
@property (nonatomic,assign) float value;
- (CGSize)measureSeekBarSize;

@end
