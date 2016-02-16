//
//  MRTextArea.h
//  mWidget
//
//  Created by Nil on 12/12/14.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"

@interface MRTextArea : MRView<MRJSView>

@property (nonatomic, strong, readonly) UITextView *textView;

- (void)fireKeyboardEvent :(NSNumber*)code;

@end
