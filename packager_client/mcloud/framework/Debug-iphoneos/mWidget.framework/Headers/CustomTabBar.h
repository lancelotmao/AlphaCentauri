//
//  TabBar.h
//  MRTabBar
//
//  Created by mCloud on 15/2/11.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TabBarItem.h"
@class CustomTabBar;
@protocol CustomTabBarDelegate <NSObject>

@optional
-(void)customTabBar:(CustomTabBar*)customTabBar selectedIndex:(NSUInteger)index;
- (NSString *)selectItem;
@end

@interface CustomTabBar : UIView
@property(nonatomic,strong)id<CustomTabBarDelegate>tabBarDelegate;
@property(nonatomic,strong)UIImage *backgroundColor_press;
@property(nonatomic,strong)UIImage *backgroundColor_normal;
@property(nonatomic,strong)UIImage *bgImage;
@property(nonatomic,strong) TabBarItem * selectedItem;
@property(nonatomic,strong)NSMutableArray *tabBarItemArray;


-(void)layoutTabBarSubviews;
- (void)clickOnItem:(TabBarItem*)tabBarItem;
@end
