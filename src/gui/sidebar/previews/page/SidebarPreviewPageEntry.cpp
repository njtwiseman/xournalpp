#include "SidebarPreviewPageEntry.h"

#include "control/Control.h"
#include "gui/sidebar/previews/base/SidebarPreviewBase.h"

SidebarPreviewPageEntry::SidebarPreviewPageEntry(SidebarPreviewPages* sidebar, PageRef page)
 : SidebarPreviewBaseEntry(sidebar, page)
 , sidebar(sidebar)
{
	XOJ_INIT_TYPE(SidebarPreviewPageEntry);

	const auto clickCallback = G_CALLBACK(+[](GtkWidget* widget, GdkEvent* event, SidebarPreviewPageEntry* self) {
		// Open context menu on right mouse click
		if (event->type == GDK_BUTTON_PRESS)
		{
			auto mouseEvent = reinterpret_cast<GdkEventButton*>(event);
			if (mouseEvent->button == 3)
			{
				self->mouseButtonPressCallback();
				self->sidebar->openPreviewContextMenu();
				return true;
			}
		}
		return false;
	});
	g_signal_connect_after(this->widget, "button-press-event", clickCallback, this);
}

SidebarPreviewPageEntry::~SidebarPreviewPageEntry()
{
	XOJ_CHECK_TYPE(SidebarPreviewPageEntry);
	XOJ_RELEASE_TYPE(SidebarPreviewPageEntry);
}

PreviewRenderType SidebarPreviewPageEntry::getRenderType()
{
	XOJ_CHECK_TYPE(SidebarPreviewPageEntry);

	return RENDER_TYPE_PAGE_PREVIEW;
}

void SidebarPreviewPageEntry::mouseButtonPressCallback()
{
	XOJ_CHECK_TYPE(SidebarPreviewPageEntry);

	sidebar->getControl()->getScrollHandler()->scrollToPage(page);
	sidebar->getControl()->firePageSelected(page);
}
