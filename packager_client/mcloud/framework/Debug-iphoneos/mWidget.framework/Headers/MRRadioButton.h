//
//  MRRadioButton1.h
//  mWidget
//
//  Created by StevenHu on 14/12/19.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"
@class RadioItem;
@interface MRRadioButton : MRView

@property (nonatomic,strong) RadioItem *radioButton;
@property(nonatomic,copy)NSString *icon;
@property(nonatomic,copy)NSString *text;
@property(nonatomic,copy)NSString * textColor;
@property(nonatomic,copy)NSString * textColor_pressed;
@property(nonatomic,copy) NSString  *textSize;
@end
