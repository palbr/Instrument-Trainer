/*!
    @file           GuiSetTranspositionDialog.cpp

    @brief          xxx.

    @author         L. J. Barman

    Copyright (c)   2008-2009, L. J. Barman, all rights reserved

    This file is part of the PianoBooster application

    PianoBooster is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PianoBooster is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PianoBooster.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <QtGui>

#include "GuiSetTranspositionDialog.h"
#include "GlView.h"

GuiSetTranspositionDialog::GuiSetTranspositionDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    m_settings = 0;
    setWindowTitle("Instrument Setup");
}


void GuiSetTranspositionDialog::init(CSettings* settings)
{
    m_settings = settings;

    clefCombo->addItem("Treble");
    clefCombo->addItem("Bass");
    clefCombo->addItem("Both");

    if (m_settings->getActiveHand() == PB_PART_right)
      clefCombo->setCurrentIndex(0);
    else if (m_settings->getActiveHand() == PB_PART_left)
      clefCombo->setCurrentIndex(1);
    else
      clefCombo->setCurrentIndex(2);

    transpositionSpin->setValue(m_settings->getMidiInputTransposition());

    //    updateTranspositionText();
}


/*void GuiSetTranspositionDialog::updateTranspositionText()
{
    currentTransposition->clear();
    // bool activateOkButton = false;

    // if (leftHandChannelCombo->currentIndex() != 0 && leftHandChannelCombo->currentIndex() == rightHandChannelCombo->currentIndex())
    //     songInfoText->append("<span style=\"color:red\">The left and rignt hand channels must be different</span>");
    // else if ((leftHandChannelCombo->currentIndex() == 0 && rightHandChannelCombo->currentIndex() != 0 ) ||
    //          (rightHandChannelCombo->currentIndex() == 0 && leftHandChannelCombo->currentIndex() != 0 ) )
    //     songInfoText->append("<span style=\"color:red\">Both left and rignt hand channels must be none to disable this feature</span>");
    // else
    // {
    //     songInfoText->append("<span style=\"color:gray\">Set the MIDI Channels to be used for left and right hand piano parts:</span>");
    //     songInfoText->append("<span style=\"color:black\">the left  hand piano part is using MIDI Channels 1</span>");
    //     songInfoText->append("<span style=\"color:black\">the right hand piano part is using MIDI Channels 1</span>");
    //     activateOkButton = true;
    // }

    // buttonBox->button(QDialogButtonBox::Ok)->setEnabled(activateOkButton);
    currentTransposition->setText(tr("%1 semitones").arg(m_settings->getMidiInputTransposition()));
    }*/

void GuiSetTranspositionDialog::accept()
{
    this->QDialog::accept();
}

void GuiSetTranspositionDialog::on_transpositionSpin_valueChanged(int value)
{
  m_settings->setMidiInputTransposition(value);
}

void GuiSetTranspositionDialog::on_clefCombo_activated(int index)
{
  if (index == 0)
    m_settings->setActiveHand(PB_PART_right);
  else if (index == 1)
    m_settings->setActiveHand(PB_PART_left);
  else
    m_settings->setActiveHand(PB_PART_both);
}
