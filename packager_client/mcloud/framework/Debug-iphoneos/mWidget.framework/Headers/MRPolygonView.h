//
//  PolygonView.h
//  MRuntime
//
//  Created by mCloud on 15/5/21.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import "MRView.h"
typedef NS_ENUM(NSInteger,Edge) {
    Edge_Left_Top,         // slow at beginning and end
    Edge_Left_Bottom,            // slow at beginning
    Edge_Right_Top,           // slow at end
    Edge_Right_Bottom
};

@interface MRPolygonView : MRView
@end
