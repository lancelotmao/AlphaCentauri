//
//  MRFragmentSwitcher.h
//  mWidget
//
//  Created by mCloud on 15/2/4.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import "MRSmartLayout.h"

@interface MRFragmentSwitcher : MRSmartLayout <MRFragmentDelegate,MRJSView>

@property(nonatomic, strong) NSMutableArray* fragments;
@property(nonatomic, strong) ActionBar *fragmentActionBar;
- (void)setInitialFragment;
- (NSUInteger)selectIndex;

@end
