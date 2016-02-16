//
//  UIPopoverListView.h
//  UIPopoverListViewDemo
//
//  Created by rossyang on 14/11/3.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MRPopupProgressView : UIView




@property (nonatomic, strong) UIView *parentView;

- (void)setTitle:(NSString *)title;

- (void)show;
- (void)dismiss;
- (void)updateProgress:(float) value;

@end
