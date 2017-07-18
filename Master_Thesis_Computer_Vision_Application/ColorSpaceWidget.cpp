#include "ColorSpaceWidget.h"

ColorSpaceWidget::ColorSpaceWidget(QWidget* parent)
	:QWidget(parent)
{

}

void ColorSpaceWidget::Initialize()
{
	InitializeLayout();
	OpenGL::RenderOptions* renderOptions = new OpenGL::RenderOptions();
	InitializeTextureGroupBox(renderOptions);
	InitializeColorSpaceGroupBox(renderOptions);
}

void ColorSpaceWidget::InitializeColorSpaceGroupBox(OpenGL::RenderOptions* renderOptions)
{
	QGroupBox* colorChannelsGroup = new QGroupBox(tr("Number of channels"), this);
	QBoxLayout* hBox1 = new QBoxLayout(QBoxLayout::Direction::LeftToRight);
	hBox1->addStretch(1);

	QBoxLayout *vBox = new QBoxLayout(QBoxLayout::Direction::LeftToRight);
	vBox->addStretch(1);
	colorChannelsGroup->setLayout(vBox);

	QRadioButton* singleChannelButton = new QRadioButton(tr("One channel"), colorChannelsGroup);
	vBox->addWidget(singleChannelButton);

	QRadioButton* trippleChannelButton = new QRadioButton(tr("Three channels"), colorChannelsGroup);
	vBox->addWidget(trippleChannelButton);
	trippleChannelButton->setChecked(true);

	hBox1->addWidget(colorChannelsGroup);

	QBoxLayout* hBox = new QBoxLayout(QBoxLayout::Direction::LeftToRight);
	hBox->addStretch(1);
	QGroupBox* actionGroup = new QGroupBox(tr("Channel 1"), this);
	SetUpColorSettingsGroup(actionGroup, 0, renderOptions);
	hBox->addWidget(actionGroup);
	QGroupBox* actionGroup2 = new QGroupBox(tr("Channel 2"), this);
	SetUpColorSettingsGroup(actionGroup2, 1, renderOptions);
	hBox->addWidget(actionGroup2);
	QGroupBox* actionGroup3 = new QGroupBox(tr("Channel 3"), this);
	SetUpColorSettingsGroup(actionGroup3, 2, renderOptions);
	hBox->addWidget(actionGroup3);

	_button_layout->addLayout(hBox1);
	_button_layout->addLayout(hBox);

	connect(trippleChannelButton, SIGNAL(toggled(bool)), actionGroup2, SLOT(setEnabled(bool)));
	connect(trippleChannelButton, SIGNAL(toggled(bool)), actionGroup3, SLOT(setEnabled(bool)));
	connect(trippleChannelButton, SIGNAL(toggled(bool)), renderOptions, SLOT(useThreeChannels(bool)));
}

void ColorSpaceWidget::SetUpColorSettingsGroup(QGroupBox * colorGroup,
	int index, OpenGL::RenderOptions* renderOptions)
{

	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addStretch(1);
	colorGroup->setLayout(vbox);
	QRadioButton * radioButton;

	for (int i = 0; i <= (int)OpenGL::ColorSpaceIndices::NUMBER_OF_INDICES; i++)
	{
		QString buttonName = OpenGL::ColorSpaceIndexTostring((OpenGL::ColorSpaceIndices)i);
		radioButton = new QRadioButton(buttonName, colorGroup);
		if (i == index)
			radioButton->setChecked(true);
		radioButton->setObjectName("" + QString::number(i) + "." + QString::number(index));
		connect(radioButton, SIGNAL(toggled(bool)), renderOptions, SLOT(setChannel(bool)));
		vbox->addWidget(radioButton);
	}


}

void ColorSpaceWidget::InitializeLayout()
{
	_main_layout = new QHBoxLayout(this);

	_texture_layout = new QVBoxLayout();
	QGroupBox* texture_group_box = new QGroupBox("texture viewerer");
	_main_layout->addWidget(texture_group_box);
	texture_group_box->setLayout(_texture_layout);

	_button_layout = new QVBoxLayout();
	_button_layout->addStretch(1);
	QGroupBox * button_group_box = new QGroupBox("Select Color Space");

	_main_layout->addWidget(button_group_box);
	button_group_box->setLayout(_button_layout);
}

void ColorSpaceWidget::InitializeTextureGroupBox(OpenGL::RenderOptions* renderOptions)
{
	QCheckBox* checkBox = new QCheckBox();
	checkBox->setText("Use RGB texture (nRGB deselected)");
	checkBox->setCheckable(true);
	checkBox->setChecked(true);
	_texture_layout->addWidget(checkBox);

	OpenGL::Texture_Viewer* texture_viewer = new OpenGL::Texture_Viewer(this);
	OpenGL::Render_Listener* listener = new OpenGL::BenchmarkTextureRenderer();
	texture_viewer->Initialize();
	texture_viewer->SetListener(listener);
	texture_viewer->SetRenderOptions(renderOptions);
	_texture_layout->addWidget(texture_viewer);
	this->setAttribute(Qt::WA_QuitOnClose);

	connect(checkBox, SIGNAL(toggled(bool)), texture_viewer, SLOT(ChangeBenchmarkTexture(bool)));
	connect(this->parent(), SIGNAL(WindowClosing()), this, SLOT(TryOnClose()));
	connect(this, SIGNAL(CloseWidget()), texture_viewer, SLOT(OnClose()));
	connect(renderOptions, SIGNAL(RenderOptionsUpdated()), texture_viewer, SLOT(updateGL()));
}

void ColorSpaceWidget::TryOnClose()
{
	emit CloseWidget();
}
