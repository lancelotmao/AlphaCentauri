//
//  MRPopupWindowUI.h
//  mWidget
//
//  Created by terry on 14/12/18.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"

@interface MRPopupWindow : MRView<MRJSView>
- (void)showAtView:(MRView *)atView withContentView:(MRView *)contentView;
@end
