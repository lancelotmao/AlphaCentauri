//
//  MRPopMenu.h
//  MRAPI
//
//  Created by mCloud on 15/1/29.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"
#import <JavaScriptCore/JavaScriptCore.h>
typedef enum {
    DesignForPopMenu,
    DesignForActionBar,
} PopMenuStye;

@protocol MRPopMenuExport <JSExport>

- (void)setChoeseCallbackForJS:(JSValue *)jsFunction;

@end
@protocol selectMenuDelegate <NSObject>

- (void)selectMenuIndex :(NSInteger)index;

@end
@interface MRPopMenu :MRView <MRPopMenuExport>
@property (nonatomic,strong) JSManagedValue *jsFunction;
@property (nonatomic,assign) id<selectMenuDelegate>selectDelegate;
@property (nonatomic, assign) PopMenuStye stye;
@property (nonatomic,strong)NSString *textBold;
@property (nonatomic,strong)NSString *menuTextColor;
@property (nonatomic, assign) CGFloat rowHeight;

-(void)showAtView:(UIView *)atview WithItems:(NSArray *)items andBgColor:(NSString*)bgColor;

@end
