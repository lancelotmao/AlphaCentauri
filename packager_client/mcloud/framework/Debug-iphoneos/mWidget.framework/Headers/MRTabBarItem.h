//
//  TabBarItem.h
//  MRTabBar
//
//  Created by mCloud on 15/2/11.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import "MRView.h"
@class TabBarItem ;
@interface MRTabBarItem : MRView
@property(nonatomic,strong,readonly) TabBarItem * tabBarItem;
@property(nonatomic,copy)NSString *icon;
@property(nonatomic,copy)NSString *text;
@property(nonatomic,copy)NSString * textColor;
@property(nonatomic,assign) CGFloat textSize;
@property(nonatomic,strong) NSString *itemId;

@end
