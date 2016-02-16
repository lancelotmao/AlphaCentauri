//
//  MRCustomDialog.h
//  mWidget
//
//  Created by Nil on 27/10/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import "MRView.h"

@interface MRCustomDialog : NSObject
- (id)initConfirmWithTitle:(NSString*)title andDic:(NSDictionary *)dic okFuction:(JSValue *)okFunction cancelFunction:(JSValue *)cancelFuction;
- (void)showCustomDialog:(NSString *)smartLayoutID sView:(MRView *)sview buttonId:(NSString *)buttonId bView:(MRView *)bview grivaty:(NSString *)grivaty;
- (void)dismissDialog;
@end
