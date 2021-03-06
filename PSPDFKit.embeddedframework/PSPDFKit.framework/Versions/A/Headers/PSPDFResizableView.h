//
//  PSPDFSelectionBorderView.h
//  PSPDFKit
//
//  Copyright (c) 2012 Peter Steinberger. All rights reserved.
//

#import "PSPDFKitGlobal.h"
#import "PSPDFLongPressGestureRecognizer.h"

@class PSPDFResizableView;

/// Delegate to be notified on session begin/end and frame changes.
@protocol PSPDFResizableViewDelegate <NSObject>

@optional

/// The editing session has begin
- (void)resizableViewDidBeginEditing:(PSPDFResizableView *)resizableView;

/// Called after frame change.
- (void)resizableViewChangedFrame:(PSPDFResizableView *)resizableView;

/// The editing session has ended
- (void)resizableViewDidEndEditing:(PSPDFResizableView *)resizableView;

@end

typedef NS_ENUM(NSUInteger, PSPDFSelectionBorderKnobType) {
    PSPDFSelectionBorderKnobTypeNone,
    PSPDFSelectionBorderKnobTypeMove,
    PSPDFSelectionBorderKnobTypeTopLeft,
    PSPDFSelectionBorderKnobTypeTopMiddle,
    PSPDFSelectionBorderKnobTypeTopRight,
    PSPDFSelectionBorderKnobTypeMiddleLeft,
    PSPDFSelectionBorderKnobTypeMiddleRight,
    PSPDFSelectionBorderKnobTypeBottomLeft,
    PSPDFSelectionBorderKnobTypeBottomMiddle,
    PSPDFSelectionBorderKnobTypeBottomRight
};

/// Handles view selection with resize knobs.
@interface PSPDFResizableView : UIView <PSPDFLongPressGestureRecognizerDelegate>

/// Designated initializer.
- (id)initWithTrackedView:(UIView *)trackedView;

/// View that will be changed on selection change.
@property (nonatomic, strong) UIView *trackedView;

/// Set zoomscale to be able to draw the page knobs at the correct size.
@property (nonatomic, assign) CGFloat zoomScale;

/// If set to NO, won't show selection knobs and dragging. Defaults to YES.
@property (nonatomic, assign) BOOL allowEditing;

/// Set minimum allowed width (unless the view is smaller to begin width). Default is 44.0.
@property (nonatomic, assign) CGFloat minWidth;
/// Set minimum allowed height (unless the view is smaller to begin width). Default is 44.0.
@property (nonatomic, assign) CGFloat minHeight;

/// Disables dragging the view outside of the parent. Defaults to YES.
@property (nonatomic, assign) BOOL preventsPositionOutsideSuperview;

/// Active knob when we're dragging.
@property (nonatomic, assign) PSPDFSelectionBorderKnobType activeKnobType;

// forward parent gesture recognizer longPress action.
- (BOOL)longPress:(UILongPressGestureRecognizer *)recognizer;

/// Delegate called on frame change.
@property (nonatomic, weak) id<PSPDFResizableViewDelegate> delegate;

@end
