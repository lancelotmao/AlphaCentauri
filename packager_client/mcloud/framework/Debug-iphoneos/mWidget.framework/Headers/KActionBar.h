//
//  KActionBar.h
//  MRuntime
//
//  Created by kefoqing on 15/8/6.
//  Copyright (c) 2015年 huawei. All rights reserved.
//



#import "MRView.h"
@interface KActionBar : MRView<UIActionSheetDelegate>
@property (nonatomic,readonly)MRView *mrView;
@property (nonatomic) BOOL active;
@property (nonatomic,strong) NSMutableDictionary *tempAttrs;

-(void)addMenuWithAttrs:(NSDictionary*)attrs andEvents:(NSDictionary*)eventHandlers;
-(void)onAttached:(MRViewController*) controller;
- (void)addBackButton;

@end
