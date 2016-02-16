//
//  MRSerchBar.h
//  mWidget
//
//  Created by mCloud on 14/12/4.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"
//@class MRUISearchBar;
@interface MRSearchBar : MRView<MRJSView>
@property(nonatomic,readonly,strong)UISearchBar *searchBar;
@end
