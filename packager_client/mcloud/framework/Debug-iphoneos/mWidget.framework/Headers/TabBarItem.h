//
//  TabBarItem.h
//  MRTabBar
//
//  Created by mCloud on 15/2/11.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TabBarItem : UIButton

@property(nonatomic,strong)UIImage  *image;
@property(nonatomic,strong)UIImage *selectedImage;
@property(nonatomic,copy)  NSString *title;
@property(nonatomic,strong)UIColor *textColor;
@property(nonatomic,strong)UIColor * selectedColor;
@property(nonatomic,assign)CGFloat textSize;
@property(nonatomic,copy)  NSString *itemId;
@property(nonatomic,assign)int badge;
@property(nonatomic,strong)UIColor *badgeFillColor;
@property(nonatomic,strong)UIColor *badgeTextColor;
@property(nonatomic,strong)UIColor *badgeBorderColor;

@property(nonatomic,strong)UIImage *backgroundColor_pressed;
@property(nonatomic,strong)UIImage *backgroundColor_normal;
@property(nonatomic,strong)UIImage *backgroundImageType;
@property(nonatomic,assign)BOOL textBold;

@end
