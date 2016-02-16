//
//  MRSmartLayout.h
//  SmartLayout
//
//  Created by mCloud on 15/4/1.
//  Copyright (c) 2015年 Alfred. All rights reserved.
//

#import "MRLayout.h"

@interface MRSmartLayout : MRLayout

@property (nonatomic, strong) UIView *smartView;

-(instancetype) initWithView:(UIView*)view;

@end
