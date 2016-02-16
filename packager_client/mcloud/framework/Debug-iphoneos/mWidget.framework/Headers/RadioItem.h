//
//  TabBarItem.h
//  MRTabBar
//
//  Created by mCloud on 15/2/11.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#define ONCHECK_PATH [[NSBundle bundleForClass:[self class]] pathForResource:@"radioYes@2x.png" ofType:nil]
#define UNCHECK_PATH [[NSBundle bundleForClass:[self class]] pathForResource:@"radioNo@2x.png" ofType:nil]

@protocol radioItemOnSelectDelegate <NSObject>
- (void)radioItemOnSelect:(BOOL)isSelected;
@end


@interface RadioItem : UIButton

@property(nonatomic,strong)UIImage  *image;
@property(nonatomic,strong)UIImage * selectedImage;
@property(nonatomic,copy)NSString *title;
@property(nonatomic,strong)UIColor *textColor;
@property(nonatomic,strong)UIColor *textColor_pressed;
@property(nonatomic,strong)UIColor * selectedColor;
@property(nonatomic,assign) CGFloat textSize;
@property(nonatomic,strong)NSString *radioItemID;
@property(nonatomic,assign)BOOL select;
@property(nonatomic,retain)id<radioItemOnSelectDelegate>radioItemDelegate;
-(CGSize)measureRadioItemSize;
@end
