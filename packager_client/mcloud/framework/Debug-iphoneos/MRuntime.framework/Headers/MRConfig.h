//
//  Config.h
//  MRuntime
//
//  Created by Lancelot on 4/25/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#ifndef MRuntime_Config_h
#define MRuntime_Config_h

#import <Foundation/Foundation.h>

#define kDocumentsPath NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0]

// store our dynamic bundles under /Documents/Frameworks
// note embedded frameworks are under /Frameworks, so we are cool
static NSString *kBundleFolder = @"Frameworks";
static NSString *kBundleFolderTmp = @"Frameworks_Tmp";

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

#define MYSCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define MYSCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height-self.navigationController.navigationBar.bounds.size.height-[UIApplication sharedApplication].statusBarFrame.size.height)
#define MYNavigationBar_HEIGHT self.navigationController.navigationBar.bounds.size.height+[UIApplication sharedApplication].statusBarFrame.size.height

#define SUFFIX_UI           @"pg"
#define SUFFIX_SCRIPT       @"act"

#endif
