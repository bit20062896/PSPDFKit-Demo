//
//  PSCChildViewController.h
//  PSPDFCatalog
//
//  Copyright (c) 2012 Peter Steinberger. All rights reserved.
//

@interface PSCChildViewController : UIViewController

@property (nonatomic, strong) PSPDFDocument *document;

- (id)initWithDocument:(PSPDFDocument *)document;

@end
