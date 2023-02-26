<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Дата на производство</h1>
                <table border="3" align="center">
                    <tr>
                        <th>Ден</th>
                        <th>Месец</th>
                        <th>Година</th>
                    </tr>
                    <xsl:for-each select="board-game-store/game/date">
                        <tr>
                            <td>
                                <xsl:call-template name="day"/>
                            </td>
                            <td>
                                <xsl:call-template name="month"/>
                            </td>
                            <td>
                                <xsl:call-template name="year"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="day">
        <xsl:value-of select="day/."/>
    </xsl:template>

    <xsl:template name="month">
        <xsl:value-of select="month/."/>
    </xsl:template>

    <xsl:template name="year">
        <xsl:value-of select="year/."/>
    </xsl:template>

</xsl:stylesheet>