//
//  MRMapView.h
//  mWidget
//
//  Created by yuangongji on 15/3/3.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import "MRView.h"

@protocol MRJSWebView <JSExport,MRJSView>

- (void)reload;
- (void)goBack;
@end
@interface MRWebView : MRView<MRJSWebView,MRJSView>
@end
