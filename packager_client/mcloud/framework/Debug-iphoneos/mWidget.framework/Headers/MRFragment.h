//
//  MRFragment.h
//  MMLInflater
//
//  Created by Lancelot on 2/17/15.
//  Copyright (c) 2015 Huawei. All rights reserved.
//

//#import "MRActionBar.h"
#import "KActionBar.h"
#import "MRJSExecutor.h"
#import "MRViewController.h"

@interface MRFragment : MRView

@property (nonatomic, weak) MRViewController* hostVC;
@property (nonatomic, strong) MRPage* page;
@property (nonatomic, copy) NSString* path;
@property (nonatomic, copy) NSString* resumeEvent;
@property (nonatomic, copy) NSString* pauseEvent;

@property (nonatomic, strong) NSData* pgData;
@property (nonatomic, strong) NSData* actData;

@end
