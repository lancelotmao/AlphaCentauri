//
//  MRTabBar.h
//  mWidget
//
//  Created by Nil on 29/12/14.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MRView.h"
#import "CustomTabBar.h"

@interface MRTabBar : MRView<MRJSView>
@property (nonatomic, strong,readonly) CustomTabBar * tabBar;
@end
