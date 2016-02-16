//
//  MRControlRect.h
//  RectToy
//
//  Created by Lancelot on 2/9/15.
//  Copyright (c) 2015 Lancelot. All rights reserved.
//

#import "MRView.h"

@interface MRControlRect : UIView

-(instancetype)initWithView:(MRView*)view;

@property (nonatomic, readwrite)CGRect rect;
@property (nonatomic, weak)MRView* view;
@property (nonatomic, strong)NSMutableArray* children;
@property (nonatomic, assign)MRControlRect* parent;
@property (nonatomic, copy)NSString* type;
@property (nonatomic, readwrite)BOOL isSelected;

@end
