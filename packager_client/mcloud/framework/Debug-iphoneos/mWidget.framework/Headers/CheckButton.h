//
//  myCheckButton.h
//  mWidget
//
//  Created by kefoqing on 14/12/19.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol checkButtonValueChangeDelegate <NSObject>
- (void)checkButtonValueChange:(BOOL)isSelected;
@end

@interface CheckButton : UIView{
}

@property (nonatomic, retain) id<checkButtonValueChangeDelegate>delegate;
@property (nonatomic, assign) BOOL isChecked;
@property (nonatomic, strong) UIImage *checkIcon;
@property (nonatomic, strong) UIImage *unCheckIcon;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *textColor_checked;
@property (nonatomic, strong) NSString *checkLabelText;
@property (nonatomic, assign) float checkLabelFont;
@property (nonatomic, assign) CGSize autoSize;
@property (nonatomic, strong) UILabel *checkLabel;
@property (nonatomic, strong)UIColor *backgrounColor;
@property (nonatomic, strong)UIImage *image;
@property (nonatomic, strong)UIColor *checkedColor;
@property (nonatomic, strong) UIButton *button;
@property (nonatomic, strong)UIImage *normalImage;
@property (nonatomic, strong)UIColor *disableColor;
@property (nonatomic, strong)UIImage *disImage;
- (CGSize)measureCheckBoxSize;

@end
