//
//  MRTextInput.h
//  mWidget
//
//  Created by Nil on 12/12/14.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"
@class TextInput;
@interface MRTextInput : MRView<MRJSView>

@property(nonatomic,readonly,strong)TextInput *textField;
@property(nonatomic, assign) id<MRDataSourceDelegate>source;
@end
