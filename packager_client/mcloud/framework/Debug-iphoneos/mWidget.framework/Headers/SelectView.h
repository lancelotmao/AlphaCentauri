//
//  UISelect.h
//  mWidget
//
//  Created by mCloud on 14/12/19.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SelectViewOnSelectedDelegate <NSObject>
- (void)selectViewOnSelectedIndex:(NSString *)value :(NSUInteger)index;
@end

@interface SelectView : UIButton
@property (nonatomic, weak)id<SelectViewOnSelectedDelegate>delegate;
@property (nonatomic,readonly)NSString *value;
@property (nonatomic,strong)NSArray *items;
@property (nonatomic,strong)UIColor *triangleColor;
@property (nonatomic,strong)NSString *textAlignmentCellLabel;
@property (nonatomic,strong)UIImage *selectImage;
@property (nonatomic,strong)UIColor *listTextNormalColor;
@property (nonatomic,strong)UIColor *listTextSelectColor;
@property (nonatomic,assign)CGFloat listTextSize;
@property (nonatomic, strong)UIImage *backImage;
@property (nonatomic, assign)NSUInteger  selectIndex;
@property (nonatomic, strong)NSString *oldSelect;

@property (nonatomic)CGSize autoSize;

@property (nonatomic,assign) CGFloat maxWidth;
@property (nonatomic,assign) CGFloat minWidth;

- (void)setTextFont:(UIFont*)font;
- (void)setTextColor:(UIColor*)color;
- (void)setCheckedItem:(NSString *)checkedItem;
@end
