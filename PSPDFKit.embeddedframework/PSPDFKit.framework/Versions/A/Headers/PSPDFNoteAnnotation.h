//
//  PSPDFNoteAnnotation.h
//  PSPDFKit
//
//  Copyright 2012 Peter Steinberger. All rights reserved.
//

#import "PSPDFAnnotation.h"

// We extend the width/height of note annotation to make them easier touch targets.
extern CGSize kPSPDFNoteAnnotationViewFixedSize;

/// PDF Note (Text) Annotation.
@interface PSPDFNoteAnnotation : PSPDFAnnotation

/// Note Icon name (see PSPDFKit.bundle for available icon names)
@property (nonatomic, copy) NSString *iconName;

/// Designated initializer.
- (id)init;

/// Custom HitTest because we have custom widht/height here.
- (BOOL)hitTest:(CGPoint)point withViewBounds:(CGRect)bounds;
- (CGRect)boundingBoxForPageViewBounds:(CGRect)pageBounds;

@end
