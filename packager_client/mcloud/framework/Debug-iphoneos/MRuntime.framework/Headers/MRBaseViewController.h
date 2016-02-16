//
//  MRBaseViewController.h
//  MRuntime
//
//  Created by lancemao on 12/7/15.
//  Copyright © 2015 Huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MRContext;

@interface MRBaseViewController : UIViewController

/*!
 @property
 @abstract page context stores page information
 @discussion
 */
@property (nonatomic, strong) MRContext* context;

/*!
 @property
 @abstract contains all contexts of all fragments
 @discussion
 */
@property (nonatomic, strong) NSMutableArray* contexts;

- (void)onStartPage:(NSString *)pageId :(NSDictionary*)data;
- (void)onFinishPage:(NSDictionary*)data;
- (id)onPushViewController :(NSString*)pageId :(NSDictionary*)data;
- (void)onPopViewController :(NSDictionary*)data;
- (NSDictionary*)onGetPageParam;

@end
